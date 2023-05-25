var chunk = (arr, size) => {
  return arr.reduce((acc, curr) => {
    const lastChunk = acc[acc.length-1];
    if (!lastChunk || lastChunk.length===size){
        acc.push([curr]);
        
    } else {
      lastChunk.push(curr);
      
    }
    return acc;
  }, [])
}
