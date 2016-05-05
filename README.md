OSP browser
===========

(temporary title)

This browser is meant to be used with the project html2print available here: <http://osp.kitchen/tools/html2print/>.
The aim is to lay out printed documents within a web browser.
We built our own webkit browser in order to have a faster browser and good typography (weirdly, the bearings and kernings can be weird in certain webkit browsers).


How to compile
--------------

    cd WebkitApp
    make


How to launch the app
---------------------

From the WebkitApp directory:

    ./WebkitApp


Available shortcuts
-------------------

- Ctrl + P: Print to file
- Ctrl + Shift + P: Print dialog (allows output page resizing)
- Ctrl + R: Reload
