import axios from "axios";

const githubToken = process.env.REACT_APP_GITHUB_TOKEN;

export const authHeaders = {
  Accept: "application/vnd.github+json",
  ...(githubToken ? { Authorization: `Bearer ${githubToken}` } : {}),
};

export const fetchRepositoryData = async (url) => {
  const res = await axios.get(url, { headers: authHeaders })
  return res.data
}
