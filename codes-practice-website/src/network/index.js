import axios from "axios";

export const authHeaders = {
  'Authorization': `Bearer ${process.env.REACT_APP_GITHUB_TOKEN}`,
  'Accept': 'application/vnd.github+json'
}

export const fetchRepositoryData = async (url) => {
  const res = await axios.get(url, { headers: authHeaders })
  return res.data
}
