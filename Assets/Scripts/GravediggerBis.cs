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
	public float shootCD = 1f;
	private float shootTimer = 0f;


	
	
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
	
	
	// the Update loop contains a very simple example of moving the character around and controlling the animation
	void Update()
	{
		// grab our current _velocity to use as a base for all calculations
		_velocity = _controller.velocity;
		
		if( _controller.isGrounded )
			_velocity.y = 0;
		
		if( Input.GetKey( KeyCode.RightArrow ) )
		{
			normalizedHorizontalSpeed = 1;
			if( transform.localScale.x < 0f )
				transform.localScale = new Vector3( -transform.localScale.x, transform.localScale.y, transform.localScale.z );
			
			//if( _controller.isGrounded )
				//_animator.Play( Animator.StringToHash( "Run" ) );
		}
		else if( Input.GetKey( KeyCode.LeftArrow ) )
		{
			normalizedHorizontalSpeed = -1;
			if( transform.localScale.x > 0f )
				transform.localScale = new Vector3( -transform.localScale.x, transform.localScale.y, transform.localScale.z );
			
			if( _controller.isGrounded )
				_animator.SetTrigger("Grounded");
		}
		else
		{
			normalizedHorizontalSpeed = 0;
			
			//if( _controller.isGrounded )
			//	_animator.Play( Animator.StringToHash( "Idle" ) );
		}
		
		
		jumpTime -= Time.deltaTime;
		if( Input.GetKey( KeyCode.UpArrow ) )
		{
			if(_controller.isGrounded){// we can only jump whilst grounded
				jumpTime=jumpPressTime;
				_velocity.y = Mathf.Sqrt( 2f * jumpHeight * -gravity );
				_animator.SetTrigger("Jump");
			}else if(jumpTime>0){
				_velocity.y = Mathf.Sqrt( 2f * jumpHeight * -gravity );
			}
		}
		
		
		// apply horizontal speed smoothing it
		var smoothedMovementFactor = _controller.isGrounded ? groundDamping : inAirDamping; // how fast do we change direction?
		_velocity.x = Mathf.Lerp( _velocity.x, normalizedHorizontalSpeed * _rawMovementDirection * runSpeed, Time.deltaTime * smoothedMovementFactor );
		
		// apply gravity before moving
		_velocity.y += gravity * Time.deltaTime;
		
		_controller.move( _velocity * Time.deltaTime );

		attackReset -= Time.deltaTime;
		if (Input.GetAxis ("Fire1")>0) {

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
		if(Input.GetAxis("Fire2")>0 && shootTimer<0){
			shootTimer=shootCD;
			_animator.SetTrigger("Fire");
			Vector3 direction = transform.localScale.x>=0 ? Vector2.right : - Vector2.right;
			Quaternion directionQuat = Quaternion.LookRotation(direction);
			Instantiate(laser,transform.position + new Vector3(0.5f,0.55f), directionQuat);
		}




		_animator.SetFloat("SpeedX", Mathf.Abs(_velocity.x));
		_animator.SetFloat("SpeedY", _velocity.y);
		_animator.SetBool ("Grounded",_controller.isGrounded);

	}

	public void EEnableReAtacck(){
		canReAttack = true;
	}

	public void EDisableReAtacck(){
		canReAttack = false;
	}

	
}