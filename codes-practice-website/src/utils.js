export const buildContentsUrl = (path = []) => {
  const normalizedPath = path.length === 0 ? "" : `${path.join("/")}/`;
  return `https://api.github.com/repos/yellowHatpro/Codes-Practice/contents/${normalizedPath}?ref=master`;
};

export const gh_url = buildContentsUrl();
