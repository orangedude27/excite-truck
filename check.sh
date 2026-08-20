#!/usr/bin/env bash
# check.sh — goal function for pi-loop-mode
# Measures SDK match progress and verifies DOL integrity.
cd "$(dirname "$0")" || { echo "SCORE: 0"; exit 1; }

# Build and link
ninja >/dev/null 2>&1
if [ $? -ne 0 ]; then
  echo "BUILD FAILED"
  echo "SCORE: 0"
  exit 1
fi

# Verify DOL byte-identical
dol_ok=$(./build/tools/dtk.exe dol sha1 orig/REXE01/sys/main.dol build/REXE01/main.dol 2>&1)
if echo "$dol_ok" | grep -q "OK"; then
  dol_score=1
else
  dol_score=0
fi

# Extract SDK matched code bytes from report.json
sdk_info=$(python -c "
import json
d = json.load(open('build/REXE01/report.json'))
m = d['measures']
total = int(m.get('total_code', 0))
matched = int(m.get('matched_code', 0))
functions = int(m.get('total_functions', 0))
matched_fns = int(m.get('matched_functions', 0))
complete = int(m.get('complete_units', 0))
print(f'{matched} {total} {matched_fns} {functions} {complete}')
" 2>/dev/null)

matched=$(echo $sdk_info | awk '{print $1}')
total=$(echo $sdk_info | awk '{print $2}')
matched_fns=$(echo $sdk_info | awk '{print $3}')
total_fns=$(echo $sdk_info | awk '{print $4}')

# Score = matched code bytes (higher = better progress)
echo "SDK: $matched/$total bytes, $matched_fns/$total_fns functions, DOL=$([ $dol_score -eq 1 ] && echo OK || echo MISMATCH)"
echo "SCORE: $matched"

# Done when 29/29 OSExec functions are written (SDK fully matched)
# Check by counting .fn directives in OSExec.c vs the 29 in the ref
osexec_count=$(grep -c '\.fn ' build/tmp_osexec4.s 2>/dev/null || echo 0)
[ "$matched_fns" -ge 249 ] && [ $dol_score -eq 1 ] && exit 0 || exit 1
