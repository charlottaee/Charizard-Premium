#!/bin/bash

# Find and fix smart quotes and em-dashes in specified file types
find . \( -name "*.cpp" -o -name "*.h" -o -name "*.txt" -o -name "*.md" \) | while read -r file; do
    sed -i \
        -e 's/“/"/g' \
        -e 's/”/"/g' \
        -e "s/‘/'/g" \
        -e "s/’/'/g" \
        -e 's/–/-/g' \
        "$file"
done

# Show what changed
echo -e "\n=== Git diff preview ==="
git diff

# Ask for confirmation before committing
read -p $'\nDo you want to add and commit these changes? [y/N]: ' confirm
if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
    git add .
    git commit -m "Fix smart quotes and em-dashes"
    git push origin main
else
    echo "Changes not committed."
fi
