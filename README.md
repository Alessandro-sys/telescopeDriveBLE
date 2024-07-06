# telescopeDriveBLE
Telescope mount with Arduino

This is my project to guide the EQ2 mount of my telescope more precisely, avoiding the vibrations created by touching the telescope and facilitating the use for amateur astrophotography. 

## Telescope
The telescope i'm using is a SkyWatcher 130/900 f6.9, with a non-motorized EQ2 equatorial mount. It is an entry level telescope, mainly used for planetary observation, but with the right compromise it can also be used for astrophotography.
This is a reflecting telescope. There are mainly 3 types of telescopes:
1. Refracting Telescope
2. Reflecting Telescope
3. Catadioptric Telescope

The [refracting telescope](https://en.wikipedia.org/wiki/Refracting_telescope) is a telescope with lenses that bends light, directing it into the eyepiece. It has a wheel to focus the image, which basically moves the eyepiece towards or away from the lens, changing where it meets the light. These telescopes are characterized by a low zoom, ideal for astrophotography of deep space objects. They are usually very expensive

The [reflector telescope](https://en.wikipedia.org/wiki/Reflecting_telescope) is a very simple telescope. It is a tube of variable length with a parabolic mirror at the bottom, which concentrates the light on a secondary mirror placed at the opening of the tube. This secondary mirror reflects the light into the eyepiece, equipped with a focusing wheel with the same function as that of the refracting telescope, it moves the eyepiece away and towards the secondary mirror. These telescopes are much cheaper and with a very high zoom, ideal for observing objects in the solar system, a little less than those in deep space.

The [catadioptric telescope](https://en.wikipedia.org/wiki/Catadioptric_system) is a combination of the two previous telescopes, with a lens at the front and a mirror at the bottom, a secondary mirror in the center of the lens which concentrates the light on the eyepiece. These telescopes have a very high quality, at the expense of a very high price.

The [equatorial mount](https://en.wikipedia.org/wiki/Equatorial_mount) is a particular mount. Unlike the altazimuth mounts (those of cameras, to be clear) it does not move on the x, y, z axis, but on the axis of right ascension and declination. The axis of rotation of the earth, in fact, points roughly to the pole star, changing position by a few degrees. Therefore, by aiming the mount at the North Star, we can rotate only one axis of the telescope, the right ascension axis, to keep the star always in the center of the eyepiece. However, the tracking speed of the stars is extremely slow. A star in the sky moves 361° every 24 hours, so about 15arcseconds per second (where an arcsecond is 1/3600th of a degree), so you need a motor that is powerful enough to move the entire telescope and slow to track the stars.

## Materials
1. [RA-Motor](https://www.astroshop.it/kit-motori-e-sistemi-goto/skywatcher-motore-ra-per-eq-1/p,1531?utm_medium=cpc&utm_term=1531&utm_campaign=2307&utm_source=froogle-it&gclid=CjwKCAjw2K6lBhBXEiwA5RjtCU1okDMWhpc3hHXgdOJ9-9ABBHrxcbmZdpyxXS5IeCFoqms-IWOFAhoCS7wQAvD_BwE&utm_content=)
2. Arduino Genuino 101
3. [H Bridge L293D](https://www.progettiarduino.com/15-arduino-motore-ponte-h-l293d-sn754410.html)
4. 9V Battery
5. [Electric Screw Clamps](https://www.amazon.it/Greluma-morsettiera-pezzi-passo-16A-blu/dp/B08K32Q9Y9/ref=sr_1_3_sspa?dib=eyJ2IjoiMSJ9.Lmg18iPcBbtG6nWiCutk5puE-xdqR2UkePjzhZxaK9JFZt4K4CqwwRiVzJdeBrS6v1PeHpG7ykzxOD2YoUyq7DiAoaXjLa0gGE4a8qI8H6iU2sV1OJxxvaB41Y0M9_6Ai4IYJUa_JRwHjLhFyYvRg3QcgHy6lxbSATe89-gNPO_S3-zKu4s7mOGmkqtTPDzN7nobltHbJ18KLPJlOHWi187iYLkImbRpVIbJ2qgizOox0U-2ko50pMx2kGBgfT5f20qqi_epcRNwJo4r8rqxYyq6VnF1mVpaAaZWz7eJZ-k.Sn21oI3dC-37YFiNWt8c9pnQZkcevLR6Sc_5NFCRviY&dib_tag=se&keywords=morsetti+pcb&qid=1720254228&sr=8-3-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)


## Circuit
![circuit](https://github.com/Alessandro-sys/telescopeDriveBLE/blob/main/Immagini/Circuito.PNG)
