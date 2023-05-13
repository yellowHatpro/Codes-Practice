const memoize = (fn) => {
    let cache = {};
    return (...args) => {
        const key = JSON.stringify(args);
        if (key in cache){
            return cache[key];
        }
        return cache[key] = fn(...args);
    }
}