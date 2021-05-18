# Crow_example

Crow is a simple web server similar to Flask from python that is gaining popularity.
Unfortunately, the documentation around Crow is poor and thus there is a lot of guessing a trying/fail situations.

Please read the notes file to better understand what is going on.

In a nutshell, we're creating just a simple website that loads an HTML with a picture, an image, and a stylesheet.
We're building the code using gcc7.3, boost latest, Pthreads, and, of course, crow headers (https://github.com/ipkn/crow/releases/tag/v0.1)

We create a docker container under which we build the code and we also run it.
We push this docker container onto Heroku.

This project is not in a finished/polished state, but it serves to demonstrate how things work.
