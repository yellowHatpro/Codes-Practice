struct Solution {}

impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let mut min_cnt = blocks.len() as i32;
        let mut cnt  = 0;
        for (i,c) in blocks.chars().enumerate() {
            if (i< k as usize){
                if (c == 'W') {
                    cnt += 1;
                }
            } else {
                min_cnt = min_cnt.min(cnt);
                let initial_char = blocks.chars().nth(i - k as usize).unwrap();
                let final_char = c;
                if (initial_char == 'W') {
                    cnt -= 1;
                }
                if (final_char == 'W') {
                    cnt += 1;
                }
            }
        }
        min_cnt.min(cnt)
    }
}