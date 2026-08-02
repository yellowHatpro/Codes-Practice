import React from "react";
import "./File.css";
import { CopyBlock } from "react-code-blocks";
import { useQuery } from "@tanstack/react-query";
import { Loading } from "../../components/Loading.jsx";

const codeTheme = {
  lineNumberColor: "#6b7280",
  lineNumberBgColor: "#eef2f7",
  backgroundColor: "#f3f6fb",
  textColor: "#1f2937",
  substringColor: "#1f2937",
  keywordColor: "#0f3d91",
  attributeColor: "#8b5cf6",
  selectorTagColor: "#0f3d91",
  docTagColor: "#6b7280",
  nameColor: "#0f172a",
  builtInColor: "#0f3d91",
  literalColor: "#0f766e",
  bulletColor: "#0f766e",
  codeColor: "#1f2937",
  additionColor: "#166534",
  regexpColor: "#be123c",
  symbolColor: "#0369a1",
  variableColor: "#1d4ed8",
  templateVariableColor: "#7c3aed",
  linkColor: "#1d4ed8",
  selectorAttributeColor: "#7c3aed",
  selectorPseudoColor: "#7c3aed",
  typeColor: "#b45309",
  stringColor: "#0f766e",
  selectorIdColor: "#b91c1c",
  selectorClassColor: "#b91c1c",
  quoteColor: "#6b7280",
  templateTagColor: "#0f3d91",
  deletionColor: "#b91c1c",
  titleColor: "#0f172a",
  sectionColor: "#0f172a",
  commentColor: "#64748b",
  metaKeywordColor: "#0f3d91",
  metaColor: "#64748b",
  functionColor: "#0f172a",
  numberColor: "#0369a1",
};

const extensionMap = {
  cpp: "cpp",
  c: "c",
  py: "python",
  js: "javascript",
  jsx: "jsx",
  ts: "typescript",
  tsx: "tsx",
  java: "java",
  rs: "rust",
  go: "go",
  css: "css",
  html: "html",
  md: "markdown",
};

const resolveLanguage = (name) => {
  const extension = name.split(".").pop()?.toLowerCase();
  return extensionMap[extension] || "text";
};

const File = ({ selectedFile, currentPath }) => {
  const { data: fileContent, error, isLoading } = useQuery({
    queryKey: ["fileContent", selectedFile?.download_url],
    enabled: Boolean(selectedFile?.download_url),
    queryFn: async () => {
      return await fetch(selectedFile.download_url).then((res) => res.text());
    },
  });

  if (!selectedFile) {
    return (
      <section className="workspace-panel file-panel file-panel-empty">
        <div className="file-summary">
          <span className="panel-kicker">Preview</span>
          <h3>Select a file from the explorer.</h3>
          <p>
            Keep browsing folders on the left. The selected source file will appear here with a
            readable code view and its full path context.
          </p>
        </div>
      </section>
    );
  }

  const language = resolveLanguage(selectedFile.name);

  return (
    <section className="workspace-panel file-panel">
      <div className="file-toolbar">
        <div className="file-summary">
          <span className="panel-kicker">Preview</span>
          <h3>{selectedFile.name}</h3>
          <p>{currentPath === "~" ? selectedFile.name : `${currentPath} / ${selectedFile.name}`}</p>
        </div>
        <div className="file-badges">
          <span className="file-badge">{selectedFile.type}</span>
          <span className="file-badge file-badge-blue">{language}</span>
        </div>
      </div>

      {isLoading && <Loading />}
      {error && !isLoading && <div className="file-feedback">Unable to load the selected file.</div>}

      {fileContent && !isLoading && !error && (
        <pre className="code-block">
          <CopyBlock
            language={language}
            text={fileContent}
            showLineNumbers={true}
            theme={codeTheme}
            wrapLines={true}
            codeBlock
          />
        </pre>
      )}
    </section>
  );
};

export default File;
