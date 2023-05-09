var filter = function(arr, fn) {
    const newArr = [];
    for (let i = 0;i<arr.length; i++){
        if (fn(arr[i],i)==true){
            newArr.push(arr[i]);
        }
    }
    return newArr;
};