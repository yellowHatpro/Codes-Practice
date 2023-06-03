var inorderTraversal = function*(arr) {
  const stack = [arr];
  while (stack.length>0) {
    const current = stack.pop();
    if (!Array.isArray(current)) {
      yield current;
      continue;
    }
    for (let i = current.length -1; i>=0; i--){
      stack.push(current[i]);
      
    }
  }
}
