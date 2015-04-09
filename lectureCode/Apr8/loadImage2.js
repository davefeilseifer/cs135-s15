


var map = document.getElementById("map");
var ctx = map.getContext("2d");


var baseImage = new Image();
baseImage.src = "assets/base.png";
baseImage.addEventListener("load", drawImage);

function drawImage(){
    ctx.drawImage(baseImage, 320, 240);
}

console.log("All Done");
