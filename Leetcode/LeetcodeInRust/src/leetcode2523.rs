pub struct Solution {}

impl Solution {
    pub fn closest_primes(left: i32, right: i32) -> Vec<i32> {
        let size = (right + 1) as usize;
        let mut is_prime = vec![true; size];
        is_prime[0] = false;
        is_prime[1] = false;
        for i in 2..size {
            if is_prime[i] {
                for j in (2*i..size).step_by(i) {
                    is_prime[j] = false;
                }
            }
        }
        let mut min_diff = i32::MAX;
        let mut last_prime = -1;
        let mut ans_last = -1;
        let mut ans_second_last = -1;
        for (i, is_num_prime) in is_prime.iter().rev().enumerate() {
            if (right as usize -i) < left as usize {
                break;
            }
            if *is_num_prime{
                if (last_prime != -1) {
                    if (last_prime - (right - i as i32) <= min_diff) {
                        ans_second_last = last_prime;
                        ans_last = right - i as i32;
                        min_diff = ans_second_last - ans_last;
                    }
                } else {
                    ans_second_last = last_prime;
                    ans_last = right - i as i32;
                    if (ans_second_last != -1) {
                        min_diff = ans_second_last - ans_last;
                        println!("{}",min_diff);
                    }
                }
                last_prime = right - i as i32;
            }
        }
        if (ans_second_last == -1 || ans_last == -1) {
            return vec![-1,-1];
        }

        vec![ans_last, ans_second_last]
    }
}