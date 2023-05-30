Function.prototype.callPolyfill = function (context, ...args) {
 Object.defineProperty(context, 'fn',{
    value: this,
    enumerable: false,
  });
  return context.fn(...args);
}
