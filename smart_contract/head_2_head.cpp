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


class head_2_head : public eosio::contract {
    public:
        using contract::contract;

        // TODO
        /// @abi action
        void creategame( std::string name ) {

            // require_auth(  );
            print( "This is the create game handler ", name );
        }

        // TODO
        /// @abi action
        void pushscore( std::string name ) {
            print( "This is the upload score handler ", name );
        }

        // TODO
        /// @abi action
        void makebet( std::string name ) {
            print( "This is the make bet handler ", name );
        }

        // TODO
        /// @abi action
        void takebet( std::string name ) {
            print( "This is the take bet handler ", name );
        }

        // TODO
        /// @abi action
        void collectwin( std::string name ) {
            print( "This is the collect winnings handler", name );
        }

    private:
        // TODO
        // @abi table game
        struct game {

            std::string             team1;
            std::string             team2;
            uint64_t                team1_score = 0;
            uint64_t                team2_score = 0;
            eosio::time_point_sec   game_time

            uint64_t primary_key()const { return id; }

            EOSLIB_SERIALIZE( game, (team1)(team2)(team1_score)(team2_score)(game_time) )

        }

        // TODO
        // typedef eosio::multi_index< N(offer), offer,> games_index;

        // TODO
        //@abi table bets
        struct bet {

            account_name            maker;
            account_name            taker;
            asset                   bet;
            eosio::time_point_sec   maker_time;
            eosio::time_point_sec   taker_time;
            uint64_t                gameid;
            
            uint64_t primary_key()const { return id; }

            uint64_t by_bet()const { return (uint64_t)bet.amount; }

            EOSLIB_SERIALIZE( offer, (maker)(taker)(bet)(maker_time)(taker_time)(game_id) )
        }

        // TODO
        // typedef eosio::multi_index< N(offer), offer,> bet_index;


        games_index games;
        bet_index   bets;

};

EOSIO_ABI( head_2_head, (creategame)(pushscore)(makebet)(takebet)(collectwin) )