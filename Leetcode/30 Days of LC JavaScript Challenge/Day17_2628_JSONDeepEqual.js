function helper(key,value) {
 if (value && typeof value === "object" && !Array.isArray(value)) {
  return Object.fromEntries(Object.entries(value).sort());
 } 

  else return value;
}

var areDeeplyEqual = function 
(o1,o2) {
  const stringfied01 = JSON.stringify(o1,helper);
  const stringfied02 = JSON.stringify(o2,helper);
  return stringfied01===stringfied02;
};
