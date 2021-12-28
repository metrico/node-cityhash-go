package main

import (
        "C"
        "fmt"
	"github.com/adubovikov/cityhash"
)

//export CityHash64
func CityHash64(input *C.char) *C.char {
	inputString := C.GoString(input)
	hash := cityhash102.CityHash64([]byte(inputString), uint32(len(inputString)))
	resString := fmt.Sprint(hash)
	return C.CString(resString)
}

//export CityHash128
func CityHash128(input *C.char) *C.char {
	inputString := C.GoString(input)
	hash := cityhash102.CityHash128([]byte(inputString), uint32(len(inputString)))
	resString := fmt.Sprint(hash)
	return C.CString(resString)
}

func main() {}

