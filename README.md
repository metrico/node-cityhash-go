# node-cityhash

> NodeJS native GO node binding providing CityHash64/128


### Build Module
```console
make
```

### Install
```
npm install -g node-cityhash-go
```
#### Usage
```
const hash = require('node-cityhash-go');
const str  = "hello"

const hash64  = hash.cityhash64(str);
const hash128 = hash.cityhash128(str);
```

#### Todo
- [x] go binding
- [x] function mapping
