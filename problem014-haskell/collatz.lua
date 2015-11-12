local memory = {}
local function collatz(n)
	if memory[n] then return memory[n] end
	if n == 1 then return 1 end

	if n % 2 == 1 then
		local val = 1 + collatz(n * 3 + 1)
		memory[n] = val
		return val
	else
		local val = 1 + collatz(n / 2)
		memory[n] = val
		return val
	end
end

local maxn = 0
local max = 0
for i = 1, 1000000 do
	local size = collatz(i)
	if size > max then
		max = size
		maxn = i
	end
end

print ('longest sequence: ' .. max)
print ('longest sequence seed: ' .. maxn)