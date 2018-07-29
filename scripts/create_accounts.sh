#!/bin/bash



# docker exec -it eosio /opt/eosio/bin/cleos -u http://0.0.0.0:8888 --wallet-url http://0.0.0.0:8888 wallet import --private-key  5J2KUqdKEMpM1LuJAr1senG3YTAkYWo52Nr2FcDT5nF4BL5vLaE && \

docker exec -it eosio /opt/eosio/bin/cleos -u http://0.0.0.0:8888 --wallet-url http://0.0.0.0:8888 create account eosio head2head EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib && \

docker exec -it eosio /opt/eosio/bin/cleos -u http://0.0.0.0:8888 --wallet-url http://0.0.0.0:8888 create account eosio user EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib && \

docker exec -it eosio /opt/eosio/bin/cleos -u http://0.0.0.0:8888 --wallet-url http://0.0.0.0:8888 create account eosio tester EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib && \

docker exec -it eosio /opt/eosio/bin/cleos -u http://0.0.0.0:8888 --wallet-url http://0.0.0.0:8888 create account eosio oracleofeos EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib EOS5w3Cxo61sbcwnLPtc1c6WKfC41zeSfwKwFZphnCkVDubssksib