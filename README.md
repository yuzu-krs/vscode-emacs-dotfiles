# VSCode Emacs Dotfiles

VSCode を Emacs キーバインド中心で使うための dotfiles です。

## 方針

- エディタ操作: Awesome Emacs Keymap (`tuttieee.emacs-mcx`)
- VSCode固有操作: `Ctrl+;` leader keybindings
- ターミナル操作: Git Bash / readline / Emacs風
- Git操作: lazygit
- テーマ: Dracula
- Neovim: 使わない

## 構成

```text
vscode-emacs-dotfiles/
  vscode/
    settings.json
    keybindings.json
    extensions.txt
  scripts/
    install-extensions.ps1
  README.md
  .gitignore
```

## セットアップ

### 1. 拡張機能を入れる

PowerShell:

```powershell
Get-Content .\vscode\extensions.txt | ForEach-Object { code --install-extension $_ }
```

または:

```powershell
.\scripts\install-extensions.ps1
```

### 2. VSCode設定を配置する

PowerShell:

```powershell
Copy-Item .\vscode\settings.json "$env:APPDATA\Code\User\settings.json" -Force
Copy-Item .\vscode\keybindings.json "$env:APPDATA\Code\User\keybindings.json" -Force
```

Git Bash:

```bash
cp vscode/settings.json "/c/Users/$USERNAME/AppData/Roaming/Code/User/settings.json"
cp vscode/keybindings.json "/c/Users/$USERNAME/AppData/Roaming/Code/User/keybindings.json"
```

## 主要キー

| 操作 | キー |
|---|---|
| ファイル検索 | `Ctrl+; f` |
| 全文検索 | `Ctrl+; s` |
| Explorer | `Ctrl+; e` |
| ターミナル | `Ctrl+; t` |
| ターミナル最大化 | `Ctrl+; m` |
| lazygit | `Ctrl+; z` |
| Copilot Chat / Agent | `Ctrl+; Alt+c` |
| Inline Chat | `Ctrl+; Alt+i` |
| Quick Fix | `Ctrl+; x` |
| 定義ジャンプ | `Ctrl+; d` |
| 戻る | `Ctrl+; ,` |
| 進む | `Ctrl+; .` |

## 注意

公開リポジトリに入れないもの:

- APIキー
- トークン
- 個人ホスト名
- `remote.SSH.remotePlatform`
- `chat.tools.terminal.autoApprove`
- 会社固有情報
- `C:\Users\<name>\...` のような個人環境パス

## Git 管理

```bash
git init -b main
git add .
git commit -m "add vscode emacs dotfiles"
git remote add origin https://github.com/yuzu-krs/vscode-emacs-dotfiles.git
git push -u origin main
```
