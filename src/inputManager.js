'using strict'

window.InputManager = function(char) {
    this.char= char;
    this.char.input={};
    this.char.input.leftPress = false;
    this.char.input.rightPress = false;
    this.char.input.jumpPress = false;
    
    // Events
    window.addEventListener("keydown", function(event) {
        var code = event.which || event.keyCode;
        if(code == 37) this.char.input.leftPress = true;
        if(code == 39) this.char.input.rightPress = true;
        if(code == 38 || code == 32) this.char.input.jumpPress = true;
    });
    window.addEventListener("keyup", function(event) {
        var code = event.which || event.keyCode;
        if(code == 37) this.char.input.leftPress = false;
        if(code == 39) this.char.input.rightPress = false;
        if(code == 38 || code == 32) this.char.input.jumpPress = false;
    });
}