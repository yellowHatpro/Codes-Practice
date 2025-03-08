pub struct Solution {}

impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = (grid.len() * grid.len()) as i32;

        let sn_wrong: i32 = grid.iter().flat_map(|row| row.iter()).sum();
        let sn2_wrong: i64 = grid.iter()
            .flat_map(|row| row.iter())
            .map(|&y| (y as i64) * (y as i64))
            .sum();

        let sn_correct = n * (n + 1) / 2;
        let sn2_correct = (n as i64) * ((n as i64) + 1) * ((2 * (n as i64)) + 1) / 6;

        let sum_diff = (sn_wrong - sn_correct) as i64;
        let sum2_diff = sn2_wrong - sn2_correct;

        let a = ((sum2_diff / sum_diff) + sum_diff) / 2;
        let b = ((sum2_diff / sum_diff) - sum_diff) / 2;

        vec![a as i32, b as i32]
    }
}
