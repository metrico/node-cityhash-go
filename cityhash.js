#!/usr/bin/env node

const cityhash = require('./');
process.argv.splice(0, 2);
var input = process.argv[0] || false;
if (!input) {
	/* pipe stdin */
	var lineReader = require('readline').createInterface({
	  input: process.stdin
	});

	/* pipe hash function */
	lineReader.on('line', function (line) {
	  const parsed = cityhash.CityHash32(line);
	  if (parsed.length>0) process.stdout.write(parsed+"\n");
	});
} else {
	process.stdout.write(cityhash.CityHash32(input+"\n");
}
