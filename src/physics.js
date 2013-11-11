var b2Vec2 = Box2D.Common.Math.b2Vec2;
var b2BodyDef = Box2D.Dynamics.b2BodyDef;
var b2Body = Box2D.Dynamics.b2Body;
var b2FixtureDef = Box2D.Dynamics.b2FixtureDef;
var b2Fixture = Box2D.Dynamics.b2Fixture;
var b2World = Box2D.Dynamics.b2World;
var b2MassData = Box2D.Collision.Shapes.b2MassData;
var b2PolygonShape = Box2D.Collision.Shapes.b2PolygonShape;
var b2CircleShape = Box2D.Collision.Shapes.b2CircleShape;
var b2DebugDraw = Box2D.Dynamics.b2DebugDraw;

window.Physics = function(element,scale) {
    var gravity = new b2Vec2(0, 9.8);
    this.world = new b2World(gravity, true);
    this.element = element;
    this.context = element.getContext("2d");
    this.scale = scale || 30;
    this.dtRemaining = 0;
    this.stepAmount = 1/60;
};


Physics.prototype.step = function (dt) {
    this.dtRemaining += dt;
    while (this.dtRemaining > this.stepAmount) {
        this.dtRemaining -= this.stepAmount;
        this.world.Step(this.stepAmount, // framerate
        8, // velocity iterations
        3); // position iterations
    }
    this.world.DrawDebugData(); // debug
    //this.world.ClearForces();
};

Physics.prototype.debug = function() {
    this.debugDraw = new b2DebugDraw();
    this.debugDraw.SetSprite(this.context);
    this.debugDraw.SetDrawScale(this.scale);
    this.debugDraw.SetFillAlpha(0.3);
    this.debugDraw.SetLineThickness(1.0);
    this.debugDraw.SetFlags(b2DebugDraw.e_shapeBit | b2DebugDraw.e_jointBit);
    this.world.SetDebugDraw(this.debugDraw);
};

var physics, lastFrame = new Date().getTime();
 
window.gameLoop = function() {
    var tm = new Date().getTime();
    requestAnimationFrame(gameLoop);
    var dt = (tm - lastFrame) / 1000;
    if(dt > 1/15) { dt = 1/15; }
    physics.step(dt);
    // Char input handler :p
    if(char.input.leftPress )
        char.body.ApplyImpulse({x:-20, y:0},char.body.GetWorldCenter());
    if(char.input.rightPress && char.body.GetLinearVelocity().x < 10)
        char.body.ApplyImpulse({x:20, y:0},char.body.GetWorldCenter());
    if(char.input.jumpPress && char.lastJump+800<lastFrame){
        console.log('jump');
        char.body.ApplyImpulse({x:0, y:-100},char.body.GetWorldCenter());
        char.lastJump=lastFrame;
    }   
    
    lastFrame = tm;
};

// shim layer with setTimeout fallback
window.requestAnimationFrame = (function(){
  return  window.requestAnimationFrame       ||
          window.webkitRequestAnimationFrame ||
          window.mozRequestAnimationFrame    ||
          function( callback ){
            window.setTimeout(callback, 1000 / 60);
          };
})();

function init() {
    physics = new window.Physics(document.getElementById("gravediggerFrame"),30);
    // Ground 
    new window.Body(physics,{ 
      type: 'static',
      shape :'block',
      x:800/60 , y: 15, 
      width : 12, height : 0.5 
    });
    
    // Character
    char=new window.Body(physics,{
      shape :'block',
      x: 800/60, y: 12.8, 
      width : 0.8, height : 1.7,
      fixedRotation: true
    });
    char.lastJump=0;
    
    new window.InputManager(char);
    physics.debug();
    requestAnimationFrame(gameLoop);
};
 
window.addEventListener("load",init);


