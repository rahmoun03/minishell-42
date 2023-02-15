while true; do
   # do stuff
   git add .
   git commit -m "script"
   git push
   tput setaf 2; echo "the project is pushed to github"
   sleep 10
done
