param([string]$name)

if (-not (Test-Path "problems")) {
	New-Item -Path "problems" -ItemType Directory | Out-Null
}
Copy-Item "templates\main_template.cpp" "problems\$name.cpp"
code "problems\$name.cpp"
New-Item -Path "problems\$name-readme.md" -ItemType File