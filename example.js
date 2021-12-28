const hash = require('./');
process.argv.splice(0, 2);

var query = process.argv[0] || 'hello'

try {
  const parsed = hash.cityhash64(query);
  console.log("query:", query);
  console.log("CityHash64:", parsed);
} catch(e){
  console.log(e);
}

try {
  const parsed = hash.cityhash128(query);
  console.log("query:", query);
  console.log("CityHash128:", parsed.toString());
} catch(e){
  console.log(e);
}
