default: build

compile-go:
	cd src/golang && go build -ldflags "-s -w" -buildmode=c-shared -o cityhash.so cityhash.go
	mv ./src/golang/cityhash.so ./cityhash.so
	strip cityhash.so

build: compile-go
	npm run build
