# Lanthaneum Daemon's JSON RPC API

## GETBLOCKCOUNT

Returns current chain height.

### getblockcount input:
```
{
	"jsonrpc": "2.0",
	"id" : "test",
	"method": "getblockcount",
		"params": {}
}
```
### getblockcount output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": {
		"count": 23520,
		"status": "OK"
	}
}
```

## GETBLOCKHASH

Returns block hash by its height.

### getblockhash input:
```
{
	"jsonrpc": "2.0",
	"id": "test",
	"method": "getblockhash",
	"params": [12345]
}
```

### getblockhash output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": "21eac691daa478dbbc3f941db0c8d5213db37035307258a164e0aa167c8b93ee"
}
```

## GETBLOCKTEMPLATE

Returns blocktemplate with an empty “hole” for nonce.

### getblocktemplate input:
```
{
	"jsonrpc": "2.0",
	"id" : "test",
	"method": "getblocktemplate",
	"params": {
		"reserve_size": 200,
		"wallet_address": "Ladpu63NXAQPuTzFNPRcSqS8CVsLM8T2w11uMjwPCXmkGc9bnHv6pY5hmreainiR9gKUQ8pHXFh6ASUHj8bfjmrwS1Wq1Lv"
	}
}
```
### getblocktemplate output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": {
		"blocktemplate_blob": "0400b9d97c00be3a53ae5fc7bb757feb1e450b731bbea8974c8b1b75023d234ac6500100d4b1dad...0000",
		"difficulty": 28852180,
		"height": 23497,
		"reserved_offset": 203,
		"status": "OK"
	}
}
```

## GETCURRENCYID

Returns unique currency identifier.

### getcurrencyid input:
```
{
	"jsonrpc": "2.0",
	"id" : "test",
	"method": "getcurrencyid"
}
```
### getcurrencyid output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": {
		"currency_id_blob": "f7657c92a306c22f1546beb2d1819c9b85696d1ba35dfa5ec423276462e25c86"
	}
}
```

## SUBMITBLOCK

Submits mined block.

### submitblock input:
```
{
	"jsonrpc": "2.0",
	"id" : "test",
	"method": "submitblock",
	"params": ["0100b...."]
}
```

### submitblock output:
```
{
	"error": {
		"code": -6,
		"message": "Wrong block blob"
	},
	"id": "test",
	"jsonrpc": "2.0"
}
```

## GETLASTBLOCKHEADER

Returns last block header.

### getlastblockheader input:
```
{
	"jsonrpc": "2.0",
	"id" : "test",
	"method": "getlastblockheader"
}
```
### getlastblockheader output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": {
		"block_header": {
			"depth": 0,
			"difficulty": 28895377,
			"hash": "74fefefaac01751f22ff8259e22f5021577f91767d66919d5e457d17917a7e49",
			"height": 23500,
			"major_version": 4,
			"minor_version": 0,
			"nonce": 1861908926,
			"orphan_status": false,
			"prev_hash": "74ace03a58e091c33886f6160cca71fc66610285d90cef74b78716a4da05bbb3",
			"reward": 200000000,
			"timestamp": 1511430619
		},
		"status": "OK"
	}
}
```

## GETBLOCKHEADERBYHASH

Returns last block header by given hash.

### getblockheaderbyhash input:
```
{
	"jsonrpc": "2.0",
	"id" : "test",
	"method": "getblockheaderbyhash",
	"params": {
		"hash" : "21eac691daa478dbbc3f941db0c8d5213db37035307258a164e0aa167c8b93ee"
	}
}
```
### getblockheaderbyhash output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": {
		"block_header": {
			"depth": 11157,
			"difficulty": 12180680,
			"hash": "21eac691daa478dbbc3f941db0c8d5213db37035307258a164e0aa167c8b93ee",
			"height": 12345,
			"major_version": 4,
			"minor_version": 0,
			"nonce": 731295514,
			"orphan_status": false,
			"prev_hash": "cc1b12a7fa3de8df11fb15c37a75d2f969d3535936afcd605369ace59721cd96",
			"reward": 100000000,
			"timestamp": 1510151512
		},
		"status": "OK"
	}
}
```

## GETBLOCKHEADERBYHEIGHT

Returns block header by given block height.

### getblockheaderbyheight input:
```
{
	"jsonrpc": "2.0",
	"id" : "test",
	"method": "getblockheaderbyheight",
	"params": {
		"height" : 12345
	}
}
```
### getblockheaderbyheight output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": {
		"block_header": {
			"depth": 11156,
			"difficulty": 12180680,
			"hash": "21eac691daa478dbbc3f941db0c8d5213db37035307258a164e0aa167c8b93ee",
			"height": 12345,
			"major_version": 4,
			"minor_version": 0,
			"nonce": 731295514,
			"orphan_status": false,
			"prev_hash": "cc1b12a7fa3de8df11fb15c37a75d2f969d3535936afcd605369ace59721cd96",
			"reward": 100000000,
			"timestamp": 1510151512
		},
		"status": "OK"
	}
}
```
## BLOCKS_LIST_JSON

Returns last 30 blocks info by given block height.

### blocks_list_json input:
```
{
	"jsonrpc": "2.0",
	"id": "test",
	"method": "blocks_list_json",
	"params": {
		"height": 12345
	}
}
```
### blocks_list_json output:
```
{
	"id": "test",
	"jsonrpc": "2.0",
	"result": {
		"blocks": [{
			"cumul_size": 198,
			"difficulty": 12180680,
			"hash": "21eac691daa478dbbc3f941db0c8d5213db37035307258a164e0aa167c8b93ee",
			"height": 12345,
			"timestamp": 1510151512,
			"tx_count": 1
		},

		*****
		
		{
			"cumul_size": 198,
			"difficulty": 11143280,
			"hash": "969fb7516d5dd1f3acc88b49e1fdf5282c36d8c09fed2df89f08ef400c314ca9",
			"height": 12315,
			"timestamp": 1510148973,
			"tx_count": 1
		}],
		"status": "OK"
	}
}
```
## Declaration
```
    static std::unordered_map<std::string, RpcServer::RpcHandler<JsonMemberMethod>> jsonRpcHandlers = {
      { "getblockcount", { makeMemberMethod(&RpcServer::on_getblockcount), true } },
      { "getblockhash", { makeMemberMethod(&RpcServer::on_getblockhash), false } },
      { "getblocktemplate", { makeMemberMethod(&RpcServer::on_getblocktemplate), false } },
      { "getcurrencyid", { makeMemberMethod(&RpcServer::on_get_currency_id), true } },
      { "submitblock", { makeMemberMethod(&RpcServer::on_submitblock), false } },
      { "getlastblockheader", { makeMemberMethod(&RpcServer::on_get_last_block_header), false } },
      { "getblockheaderbyhash", { makeMemberMethod(&RpcServer::on_get_block_header_by_hash), false } },
      { "getblockheaderbyheight", { makeMemberMethod(&RpcServer::on_get_block_header_by_height), false } }
    };
```