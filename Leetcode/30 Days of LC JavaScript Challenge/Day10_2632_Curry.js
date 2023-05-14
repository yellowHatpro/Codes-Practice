var curry = fn => (...args) => {
    if (args.length>= fn.length){
        return fn(...args);
    }
    return (...nextArgs) => {
        return curry(fn)(...args, ...nextArgs);
    }
}