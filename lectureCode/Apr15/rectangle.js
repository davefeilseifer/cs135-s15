
function Rectangle(l, w){
    this.length = l;
    this.width = w;
    this.perimeter = 2 * (l + w);
    this.area = l * w;
}

var foo = new Rectangle(10, 12);
var bar = new Rectangle(3, 4);

var outputString1 = "Foo's length is: " + foo.length + "<br> Bar's Length is: " + bar.length;
var outputString2 = "Foo's area is: " + foo.area + "<br> Bar's area is: " + bar.area;

document.getElementById("stuff").innerHTML = outputString1 + "<br> " + outputString2;
console.log(outputString1 + outputString2);

foo.length = 4;
console.log("Foo's length: " + foo.length);
console.log("Foo's width: " + foo.width);
console.log("Foo's area: " + foo.area); // not good



function BetterRectangle(l, w){
    this.length = l;
    this.width = w;
    this.perimeter = 2 * (l + w);
    this.area = l * w;

    this.area = function(){
	return this.length * this.width;
    }
    this.perimeter = function(){
	return (this.length + this.width) * 2;
    }

    this.diagonalLength = function(){
	return math.sqrt(this.length * this.length + this.width * this.width);
    }

}

var foofoo = new BetterRectangle(10, 12);

console.log("FooFoo's length: " + foofoo.length);
console.log("FooFoo's width: " + foofoo.width);
console.log("FooFoo's area: " + foofoo.area()); // good because
foofoo.length = 3;

console.log("FooFoo's area: " + foofoo.area()); // works