local json = require("json")
local parser = require("redis.parser")
local res = ngx.location.capture("/get_redis",{args = { key = ngx.var.arg_key }})

if res.status == 200 then
   reply = parser.parse_reply(res.body)
   value = json.encode(reply)
   ngx.say(value)
	a = json.decode(value)
	ngx.say(a[2])
end


