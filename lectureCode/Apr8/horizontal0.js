


var map = document.getElementById("map");
var ctx = map.getContext("2d");


var baseImage = new Image();
baseImage.src = "assets/base.png";
baseImage.addEventListener("load", update)

var x = 0;
function update(){
    for(var i = 0; i < 100; i++){
	ctx.drawImage(baseImage, x, 240);
	x = x + 1;
    }

}

console.log("All Done");
