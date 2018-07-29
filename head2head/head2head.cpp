#include <string>
#include <eosiolib/eosio.hpp>
#include <eosiolib/time.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/contract.hpp>
#include <eosiolib/crypto.h>
#include <eosiolib/print.hpp>


using eosio::indexed_by;
using eosio::const_mem_fun;
using eosio::asset;
using eosio::permission_level;
using eosio::action;
using eosio::print;
using eosio::name;


class head2head : public eosio::contract {
    public:
        head2head(account_name self)
        :eosio::contract(self),
        _games(_self, _self),
        _bets(_self, _self)
        {}

        const uint32_t TWENTY_FOUR_HOURS = 86400;

        /// @abi action
        void creategame( std::string team1, std::string team2, std::string league, uint128_t time_in_seconds ) {

            // authorization for account holding contract
            require_auth( _self );

            _games.emplace( _self, [&]( auto& g ) {
                g.id = _games.available_primary_key();
                g.team1 = team1;
                g.team2 = team2;
                g.league = league;
                g.team1_score = 0;
                g.team2_score = 0;
                g.game_time = eosio::time_point_sec(time_in_seconds);
            });

            auto itr = _games.crbegin();
            print("Game was successfully saved", "\n", "Game Id:  ", itr->id, "\n");
        }


        /// @abi action
        void deletegame(uint64_t id) {

            // authorization for account holding contract
            require_auth( _self );

            // find game by id
            auto iter=_games.find(id);

            eosio_assert(iter != _games.end(), "Game not found");

            _games.erase(iter);
        }


        /// @abi action
        void updatescore( const uint64_t id, const uint64_t team1_score, const uint64_t team2_score ) {

            require_auth( N(oracleofeos) );

            auto iter=_games.find(id);

            eosio_assert(iter != _games.end(), "Game not found");

            _games.modify( iter, _self , [&]( auto& g ) {
                g.team1_score = team1_score;
                g.team2_score = team2_score;
            });

            auto game = _games.get(id);
            print( "Score Updated for ", game.team1, " vs ", game.team2 );
        }


        // TODO
        /// @abi action
        void makebet( const uint64_t game_id, const account_name maker, const asset& bet, const std::string winner ) {

            // assert that maker is a real account
            eosio_assert( is_account( maker ), "Bet maker account does not exist.");

            // assert that maker has the required authority to make bet
            require_auth( maker );

            // check submitted asset
            eosio_assert( bet.symbol.is_valid(), "Currency symbol is invalid." );
            eosio_assert( bet.is_valid(), "invalid quantity" );
            eosio_assert( bet.amount > 0, "must deposit positive quantity" );

            auto iter = _games.find(game_id);

            // assert whether asset exists
            eosio_assert(iter != _games.end(), "Game not found.");

            // assert that current time is not greater than game_time
            eosio_assert( eosio::time_point_sec(now()) < iter->game_time, "Game has already started unable to make bets.");

            // check that winner matches a team
            eosio_assert((iter->team1 == winner || iter->team2 == winner) , "Winner does not match any team in the selected game.");

            // create bet with with bet amount held out
            // TODO change payor
            auto new_bet_itr = _bets.emplace(_self, [&](auto& b){
                b.id        =           _bets.available_primary_key();
                b.maker     =           maker;
                b.game_id   =           game_id;
                b.bet_creation_time =   eosio::time_point_sec(now());
                b.maker_winner    =     winner;
            });

            // transfer eos from maker to head2head token pool
            action(
                    permission_level{ maker, N(active) },
                    N(eosio.token), N(transfer),
                    std::make_tuple(maker, _self, bet, std::string(""))
            ).send();

            // TODO change payor
            _bets.modify( new_bet_itr, _self, [&]( auto& b ) {
                b.amount = bet;
            });

            print("Game was successfully saved! ", "Bet Id: ", new_bet_itr->id, " Bet amount: ", new_bet_itr->amount);
        }

        // TODO
        // add both teams that need to be deleted to ensure fail safe
        /// @abi action
        void deletebet(uint64_t id) {

            // authorization for account holding contract
            require_auth( _self );

            // find game by id
            auto iter=_bets.find(id);

            eosio_assert(iter != _bets.end(), "Bet not found");

            // TODO SEND MONEY BACK TO MAKER AND OR TAKER ACCOUNT

            _bets.erase(iter);

        }


        // TODO
        /// @abi action
        void takebet( const uint64_t game_id, const uint64_t bet_id, const account_name taker, const asset& bet ) {

            // assert that maker is a real account
            eosio_assert( is_account( taker ), "Bet taker account does not exist.");

            // assert that maker has the required authority to make bet
            require_auth( taker );

            // check submitted asset
            eosio_assert( bet.symbol.is_valid(), "Currency symbol is invalid." );
            eosio_assert( bet.is_valid(), "invalid quantity" );
            eosio_assert( bet.amount > 0, "must deposit positive quantity" );

            // find game
            auto game_iter = _games.find(game_id);

            // assert whether game exists
            eosio_assert(game_iter != _games.end(), "Game not found.");

            // assert that current time is not greater than game_time
            eosio_assert( eosio::time_point_sec(now()) < game_iter->game_time, "Game has already started unable to take bets.");

            print("Team 1: ", game_iter->team1, "; ", "Team 2: ", game_iter->team2);

            // find game
            auto bet_iter = _bets.find(bet_id);

            // assert whether bet exists
            eosio_assert(bet_iter != _bets.end(), "Game not found.");

            // assert that maker does not equal taker
            // cannot bet against own account
            eosio_assert( taker != bet_iter->maker , "Bet taker cannot be the same as the maker of the bet");


            // add check that taker field is empty
            eosio_assert( is_account( bet_iter->taker ) , "Someone has already taken this bet.");


            if(bet_iter->maker_winner == game_iter->team1) {
                // TODO change payor
                _bets.modify( bet_iter, _self, [&]( auto& b ) {
                    b.taker = taker;
                    b.taker_winner = game_iter->team2;
                });
            } else {
                // TODO change payor
                _bets.modify( bet_iter, _self, [&]( auto& b ) {
                    b.taker = taker;
                    b.taker_winner = game_iter->team1;
                });
            }
        }


        // TODO
        /// @abi action
        void collectwin( std::string name ) {
            print( "This is the collect winnings handler", name );
        }


        // toggles whether contract is accepting new bets
        /// @abi action
        void tacceptbets() {}

    private:
        //@abi table game i64
        struct game {
            uint64_t                id;
            std::string             team1;
            std::string             team2;
            std::string             league;
            uint64_t                team1_score;
            uint64_t                team2_score;
            eosio::time_point_sec   game_time;

            uint64_t primary_key()const { return id; }

            EOSLIB_SERIALIZE( game, (id)(team1)(team2)(league)(team1_score)(team2_score)(game_time) )
        };

        typedef eosio::multi_index< N(game), game> game_index;

        //@abi table bet i64
        struct bet {
            uint64_t                id;
            account_name            maker;
            account_name            taker;
            uint64_t                game_id;
            asset                   amount;
            std::string             maker_winner="";
            std::string             taker_winner="";
            eosio::time_point_sec   bet_creation_time;

            uint64_t primary_key()const { return id; }

            // TODO add secondary index for game id

            EOSLIB_SERIALIZE( bet, (id)(maker)(taker)(game_id)(amount)(maker_winner)(taker_winner)(bet_creation_time) )
        };

        typedef eosio::multi_index< N(bet), bet> bet_index;

        game_index          _games;
        bet_index           _bets;

};

EOSIO_ABI( head2head, (creategame)(deletegame)(updatescore)(makebet)(deletebet)(takebet)(collectwin)(tacceptbets) )