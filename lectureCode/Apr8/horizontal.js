


var map = document.getElementById("map");
var ctx = map.getContext("2d");


var baseImage = new Image();
baseImage.src = "assets/base.png";
baseImage.addEventListener("load", drawImage);

var dt = 1000/30.0;

function drawImage(){
    setInterval(update, 1000/30.0);
}

var x = 0;
var speed = 0.3;
var direction = 1;
function update(){
    ctx.clearRect(0, 0, map.width, map.height);
    ctx.drawImage(baseImage, x, map.height - baseImage.height);
    x += speed * direction * dt;
    if (x > map.width - baseImage.width || x < 0)
	direction = -direction;

}

console.log("All Done");
