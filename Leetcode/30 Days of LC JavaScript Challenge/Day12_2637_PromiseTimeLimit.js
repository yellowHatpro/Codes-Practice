var timeLimit = (fn,t) => async (...args) => {
    return new Promise((resolve,reject) => {
        const timeout = setTimeout(()=> {
            reject('Time Limit Exceeded');
        }, t);
        fn(...args).then(resolve).catch(reject).finally(() => {
            clearTimeout(timeout);
        })
    })
}