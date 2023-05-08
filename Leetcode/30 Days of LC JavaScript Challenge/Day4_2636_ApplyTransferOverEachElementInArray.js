//~250ms for 5M elements 
var map = function(arr, fn) {
    const newArr = [];
    for (let i = 0; i < arr.length; ++i){
        newArr[i] = fn(arr[i],i);
    }
    return newArr;
};

//~1000ms for 5m elements
var map = function(arr, fn) {
    const newArr = new Array(arr.length);
    for (const i in arr){
        newArr[i] = fn(arr[i],Number(i));
    }
    return newArr;
};

//~200ms for 5M elements
var map = function(arr, fn){
    const newArr = [];
    for (let i = 0; i <arr.length; i++){
        newArr.push(fn(arr[i],i));
    }
};

//~40ms for 5M elements
var map = function(arr, fn) {
    const newArr = new Array(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};

//~20ms for 5M elements
var map = function(arr, fn) {
    const newArr = new Int32Array(arr.length);
    for (let i = 0; i < arr.length; ++i) {
        newArr[i] = fn(arr[i], i);
    }
    return newArr;
};

//~10ms for 5M elements
var map = function(arr, fn) {
    for (let i = 0; i < arr.length; ++i) {
        arr[i] = fn(arr[i], i);
    }
    return arr;
};


