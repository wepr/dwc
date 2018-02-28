// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
// DWC and ZZP proposal [--- DWC ---]

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 117;//Prefix of the wallet address: start with 135=ZZP, 117=DWC
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 18;// 4=ZZP, 18=DWC
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

const uint64_t MONEY_SUPPLY                                  = static_cast<uint64_t>(-1);//Total amount of atomic units to be emitted

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1048576; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 1048576;  //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;//8=DWC, 4=ZZP

const uint64_t COIN                                          = UINT64_C(100000000);// COIN - number of smallest units in one coin: 10000=ZZP, 100000000=DWC
const uint64_t MINIMUM_FEE                                   = UINT64_C(1);// Transactions with less than this fee wouldn’t be accepted by daemons
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(2);//The amount bellow this value will be considered as dust: ZZP=1, DWC=2

const uint64_t REAL_COINS_LIMITED_Z                          = UINT64_C(10000000);//Total amount of coins mineable with full reward: 10000000=DWC,10000000000=ZZP
const uint64_t MONEY_SUPPLY_MINEABLE_Z                       = REAL_COINS_LIMITED_Z*COIN;//Total amount of atomic units mineable with full reward
const size_t   RUSH_BLOCKS_Z                                 = 1000;//Premium rewarded blocks count: ZZP=500, DWC=1000
const uint64_t RUSH_REWARD_Z                                 = (UINT64_C(100)*COIN);//Reward for a premium block: ZZP=200000, DWC=100
const uint64_t COMMON_REWARD_Z                               = (UINT64_C(1)*COIN);//Reward for an ordinary block: ZZP=1000, DWC=1
const uint64_t GENESIS_BLOCK_REWARD_Z                        = (UINT64_C(9999800)*COIN);//Premine amount, in atomic units: DWC=50000, ZZP=10.000.000
const size_t   RUSH_REWARD_LOCK_Z                            = 750000;//Premium rewarded blocks lock time: ZZP=20000, DWC=750000

const uint64_t DIFFICULTY_TARGET                             = 20;//Difficulty target is an ideal time period between blocks, in seconds. 20=DWC, 720=ZZP
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY/12; // blocks
const size_t   DIFFICULTY_CUT                                = 60;//Timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 20;//Lag of calculating the difficulty in terms of blocks

static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   DIFFICULTY_FNC_VER                            = 0;//0=DWC, 2=ZZP
const uint32_t DIFFICULTY_ZAWY_START_BLOCK                   = 24000;//24000=DWC, 1=ZZP
const size_t   DIFFICULTY_ZAWY_WINDOW                        = 30;//30=DWC, 12=ZZP

const uint64_t DEPOSIT_MIN_AMOUNT                            = 0.01 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 11000;
const uint32_t DEPOSIT_MAX_TERM                              = 10 * 12 * 11000;
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 77000;
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 11;

static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 4); //seconds, 4 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 8); //seconds, 8 hours
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 2;
const uint32_t UPGRADE_HEIGHT_V3                             = 3;
const uint32_t UPGRADE_HEIGHT_V4                             = 4;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "chain.data";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "idx.data";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "cache.data";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "mempool.data";
const char     P2P_NET_DATA_FILENAME[]                       = "p2p.data";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "chainidx.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "common.json";
} // parameters

const uint64_t TIMESTAMP_HACK_1_BLOCK_HEIGHT_Z               = 1;//400000=DWC, 1=ZZP
const uint64_t TIMESTAMP_HACK_1_FUTURE_TIME_LIMIT_Z          = 60 * 7;//420 seconds/21 block = DWC

const uint64_t START_BLOCK_REWARD                            = (UINT64_C(320000) * parameters::COIN);
const uint64_t MIN_BLOCK_REWARD                              = (UINT64_C(150) * parameters::COIN);
const uint64_t REWARD_HALVING_INTERVAL                       = (UINT64_C(11000));

const char     CRYPTONOTE_TICKER[]                           = "DWC";
const char     CRYPTONOTE_NAME[]                             = "Darwincoin";

const char GENESIS_COINBASE_TX_HEX[] = "010101ff0000210190caf9441a87dfaa925c34860c8fc71807d15491af159d259c1d0c4ab8dba977";

const uint32_t GENESIS_NONCE                                 = 24;
const char     GENESIS_WALLET_Z[]                            = "";

//CRYPTONOTE_NETWORK is defined @ \P2p\P2pNetworks.h
//CRYPTONOTE_NETWORK = 24d91a1b-3aa0-6ddf-3eab-e0b4fb48f9e9
//const static boost::uuids::uuid CRYPTONOTE_NETWORK = { { 0x24, 0xD9, 0x1A, 0x1B, 0x3A, 0xA0, 0x6D, 0xDF, 0x3E, 0xAB, 0xE0, 0xB4, 0xFB, 0x48, 0xF9, 0xE9 } };

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              = 17272;//ZZP=33721, DWC=33711
const int      RPC_DEFAULT_PORT                              = 17273;//ZZP=33722, DWC=33712

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  512;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  2048;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 300;           // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 64;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "ab99e468743e62c86e6d07a0db4f26db5fa6c46dc2ee899b459b3a205385d460";

const std::initializer_list<const char*> SEED_NODES = {
	"127.0.0.1:17272",  
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {


};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
