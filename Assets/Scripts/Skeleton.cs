using UnityEngine;
using System.Collections;

public class Skeleton : MonoBehaviour {

	// The skeleton can be in differents states:
	// - idle (waiting for the player to come around to awake)
	// - awaking (the skeleton have detected a player, he have to stand up)
	// - idleing (the skeleton is out of the player range, he is going down to idle)
	// - moving (after standing up, the skeleton will now walk to try to reach the player)
	// - attacking (after reaching the player, the skeleton will now try to attack the player)


	// The distance between the skeleton & the player required to return the skeleton to sleep.
	public float distanceToIdle = 5.0f;
	// The distance between the skeleton & the player required to wake-up the skeleton.
	public float distanceToAwake = 4.0f;
	// The distance between the skeleton & the player required to attack with the skeleton.
	public float distanceToAttack = 1.0f;

	// The speed of the skeleton.
	public float speed = 2.0f;

	// Reference to the player's transform to calculate the distance between the player and the skeleton.
	private Transform player;
	// The direction of the skeleton, right or left.
	private int direction = 1;
	// The animator containing the states of the skeleton
	private Animator animator;

	private bool isAwake;
	private bool isPushBack;

	// This function will move the skeleton toward the player, turning the sprite in the good direction.
	void moveTowardPlayer() {
		setTransformFacingPlayer ();
		transform.Translate (direction * speed * Time.deltaTime, 0, 0);		
	}

	void setTransformFacingPlayer() {
		if (transform.position.x > player.position.x) {
			direction = -1;
		} else {
			direction = 1;
		}
		transform.localScale = new Vector3 (direction, 1, 1);
	}

	private PushBack pushBack;

	void isPushedAwayFromPlayer() {
		setTransformFacingPlayer ();
		transform.Translate (-direction * speed * Time.deltaTime, speed * Time.deltaTime, 0);		
	}
	
	// Use this for initialization
	void Start () {
		// Setting up the reference to player
		player = GameObject.FindGameObjectWithTag("GD").transform;
		animator = GetComponent<Animator>();
		pushBack = this.GetComponent<PushBack> ();
	}

	// Update is called once per frame
	void Update () {
		if (pushBack.isPushed ()) {
			isPushedAwayFromPlayer();
		} else {
			float xDistance = Mathf.Abs (transform.position.x - player.position.x);
			// State "Attacking"
			if (xDistance <= distanceToAttack) {
				animator.SetTrigger ("Eating");
			// State "Awaking"
			} else if (!isAwake && xDistance <= distanceToAwake) {
				animator.SetTrigger ("Awaking");
				isAwake = true;
			// State "Walking"
			} else if (isAwake && xDistance <= distanceToIdle) {
				animator.SetTrigger ("Walking");
				// TODO: Need to check if the animator IS in the "Walking" state to make him really move,
				// Because it can still be in the "Awaking" state, where it shouldn't already move.
				moveTowardPlayer();
			// State Idle-ing
			} else if (isAwake && xDistance > distanceToIdle) {
				isAwake = false;
				animator.SetTrigger ("Idle-ing");
			}
		}
	}
	
}

















