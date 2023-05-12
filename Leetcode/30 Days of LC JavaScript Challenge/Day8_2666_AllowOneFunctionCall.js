var once = function(fn) {
    let called = false;
    return (...args) => {
        if (!called){
            called = true;
            return fn(...args);
        }
    }
}

//Bind Function to a Context
var once = function(fn) {
    let hasBeenCalled = false;
    return function(...args){
      if (!hasBeenCalled) {
        hasBeenCalled = true;
        return fn.apply(this, args);
      }
    }
  };