var reduce = function(nums, fn, init) {
    let accumulator = init;
    for (const num of nums) {
        accumulator = fn(accumulator, num);
    }
    return accumulator;
};
var reduce = function(nums,fn,init) {
    let accumulator = init;
    for (const idx in nums) {
        accumulator = fn(accumulator,nums[idx]);
    }
    return accumulator;

}
var reduce = function(nums, fn, init) {
    let accumulator = init;
    nums.forEach((ele)=> {
        accumulator = fn(accumulator,ele);
    })
    return accumulator;
}