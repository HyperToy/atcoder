cd ~/Documents/1_kyoPro/atcoder/
find . -type f -regex .*\/[a-z] | xargs rm

git switch main
git merge develop
git push
git switch develop

git log -1 --oneline
