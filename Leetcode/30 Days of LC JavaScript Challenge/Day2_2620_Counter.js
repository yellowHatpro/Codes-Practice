//Closures 
var createCounter = function(n) {
    return () => n++;
};

var createCounter = function(n) {
    return function() {
        return n++;
    }
}
