var createCounter = function(init) {
    let curr = init;
    return {
        increment: () => ++curr,
        decrement: () => --curr,
        reset: () => (curr = init)
    }
};

//Other ways:
//1. Closure:
var createCounter = function(init) {
    let curr = init;
    return{
        increment: function() {
            return ++curr;
        },
        decrement: function() {
            return --curr;
        },
        reset: function() {
            return curr = init;
        }
    }
};

//2. Create class
class Counter {
    constructor(init) {
        this.init = init;
        this.curr = init;
    }
    increment() {
        this.curr++;
        return this.curr;
    }
    decrement() {
        this.curr--;
        return this.curr;
    }
    reset() {
        this.curr = this.init;
        return this.curr;
    }
}

var createCounter = function(init) {
    return new Counter(init);
};
