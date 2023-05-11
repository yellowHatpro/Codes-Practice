/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        let value = x;
        for (let i=functions.length-1; i>=0; i--){
            value = functions[i](value);
        }
        return value;
    };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 **/

//2nd attempt
var compose = (functions) => (x) => {
    for (let i = functions.length - 1; i >= 0; i--) {
        x = functions[i](x);
    }
    return x;
}

//Using for..of loop
var compose = (functions) => (x) => {
    let inp = x;
    for (const fn of functions.reverse()){
        inp = fn(inp);
    }
    return inp;
}

//array.reduceRight()
var compose = (functions) => (x) => {
    return functions.reduceRight((acc, fn) => fn(acc),x)
}

//reduceRight 1 liner
var compose = (functions) => (x) => functions.reduceRight((acc, fn) => fn(acc),x)
