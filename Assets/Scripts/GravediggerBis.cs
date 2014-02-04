using UnityEngine;
using System.Collections;


public class GravediggerBis : MonoBehaviour
{
	// movement config
	public float gravity = -15f;
	public float runSpeed = 5.5f;
	public float groundDamping = 20f; // how fast do we change direction? higher means faster
	public float inAirDamping = 5f;
	public float jumpHeight = 0.5f;
	public float attackSpeed =0.8f; 
	public float jumpPressTime = 0.35f;
	
	[HideInInspector]
	private float _rawMovementDirection = 1;
	[HideInInspector]
	private float normalizedHorizontalSpeed = 0;
	
	private CharacterController2D _controller;
	private Animator _animator;
	private RaycastHit2D _lastControllerColliderHit;
	private Vector3 _velocity;

	private float attackReset = 0f;
	private bool attackPress = false;
	private bool canReAttack = false;

	private float jumpTime = 0f;

	public GameObject laser;
	public ParticleSystem particle;
	public float shootCD = 1f;
	private float shootTimer = 0f;
	private bool shoot = false;
	private bool fireButtonReleased = true;
	private ParticleSystem particleInstance;


	
	
	void Awake()
	{
		_animator = GetComponent<Animator>();
		_controller = GetComponent<CharacterController2D>();
		_controller.onControllerCollidedEvent += onControllerCollider;
	}
	
	
	void onControllerCollider( RaycastHit2D hit )
	{
		// bail out on plain old ground hits
		if( hit.normal.y == 1f )
			return;
		
		// logs any collider hits if uncommented
		//Debug.Log( "flags: " + _controller.collisionState + ", hit.normal: " + hit.normal );
	}
	
	
	void Update()
	{
		move ();
		attack ();
	}

	private void move(){
		// grab our current _velocity to use as a base for all calculations
		_velocity = _controller.velocity;
		
		if (_controller.isGrounded)
			_velocity.y = 0;
		
		if (Input.GetKey (KeyCode.RightArrow)) {
			normalizedHorizontalSpeed = 1;
			if (transform.localScale.x < 0f) {
				transform.localScale = new Vector3 (-transform.localScale.x, transform.localScale.y, transform.localScale.z);
			}
		} else if (Input.GetKey (KeyCode.LeftArrow)) {
			normalizedHorizontalSpeed = -1;
			if (transform.localScale.x > 0f) {
				transform.localScale = new Vector3 (-transform.localScale.x, transform.localScale.y, transform.localScale.z);
			}
			if (_controller.isGrounded) {
				_animator.SetTrigger ("Grounded");
			}
		} else {
			normalizedHorizontalSpeed = 0;
		}

		jumpTime -= Time.deltaTime;
		if (Input.GetKey (KeyCode.UpArrow)) {
			if (_controller.isGrounded) {// we can only jump whilst grounded
				jumpTime = jumpPressTime;
				_velocity.y = Mathf.Sqrt (2f * jumpHeight * -gravity);
				_animator.SetTrigger ("Jump");
			} else if (jumpTime > 0) {
				_velocity.y = Mathf.Sqrt (2f * jumpHeight * -gravity);
			}
		}
		
		
		// apply horizontal speed smoothing it
		var smoothedMovementFactor = _controller.isGrounded ? groundDamping : inAirDamping; // how fast do we change direction?
		_velocity.x = Mathf.Lerp (_velocity.x, normalizedHorizontalSpeed * _rawMovementDirection * runSpeed, Time.deltaTime * smoothedMovementFactor);
		
		// apply gravity before moving
		_velocity.y += gravity * Time.deltaTime;
		
		_controller.move (_velocity * Time.deltaTime);

		_animator.SetFloat("SpeedX", Mathf.Abs(_velocity.x));
		_animator.SetFloat("SpeedY", _velocity.y);
		_animator.SetBool ("Grounded",_controller.isGrounded);
	}

	private void attack(){
		attackReset -= Time.deltaTime;
		if (Input.GetAxis ("Fire1") > 0) {
			if (attackReset <= 0 && !attackPress) {
				_animator.SetTrigger ("Attack");
				attackReset = attackSpeed;
			} else if (canReAttack && !attackPress) {
				_animator.SetTrigger ("Attack2");
				canReAttack = false;
			}
			attackPress = true;
		} else {
			attackPress = false;
		}
				
		shootTimer -= Time.deltaTime;
		if(fireButtonReleased && Input.GetAxis("Fire2")>0 && shootTimer<0){
			shootTimer=shootCD;
			_animator.SetTrigger("Fire");
			Vector3 direction = transform.localScale.x >= 0 ? Vector2.right : - Vector2.right;
			Quaternion directionQuat = Quaternion.LookRotation (direction);
			Vector3 position = transform.FindChild ("LaserSpawnPosition").position;
			// Instantiate (laser, position, directionQuat);
			shoot=true;
			particleInstance =  Instantiate (particle,position,directionQuat) as ParticleSystem;
			fireButtonReleased = false;
			Debug.Log ("Fire pressed");
		}

		 if (!fireButtonReleased && shoot && (Input.GetAxis ("Fire2") <= 0 || particleInstance==null || !particleInstance.IsAlive())) {
			_animator.SetTrigger("Fired");
			Vector3 direction = transform.localScale.x >= 0 ? Vector2.right : - Vector2.right;
			Quaternion directionQuat = Quaternion.LookRotation (direction);
			Vector3 position = transform.FindChild ("LaserSpawnPosition").position;
			GameObject laserShoot=Instantiate (laser, position, directionQuat) as GameObject ;
			Destroy(laserShoot, 1);
			Destroy(particleInstance.gameObject);
			Debug.Log ("fire released");
			shoot = false;
		}
		if(Input.GetAxis ("Fire2") <= 0){
			fireButtonReleased = true;
		}
	}

	public void EEnableReAtacck(){
		canReAttack = true;
	}

	public void EDisableReAtacck(){
		canReAttack = false;
	}

	
}