$ErrorActionPreference = "Stop"

$extensionsFile = Join-Path $PSScriptRoot "..\vscode\extensions.txt"

if (-not (Test-Path $extensionsFile)) {
  Write-Error "extensions.txt not found: $extensionsFile"
  exit 1
}

Get-Content $extensionsFile | Where-Object { $_.Trim() -ne "" } | ForEach-Object {
  Write-Host "Installing extension: $_"
  code --install-extension $_
}

Write-Host "Done."
