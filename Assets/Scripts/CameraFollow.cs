using UnityEngine;
using System.Collections;

public class CameraFollow : MonoBehaviour 
{

	public Vector2 maxXAndY;		// The maximum x and y coordinates the camera can have.
	public Vector2 minXAndY;		// The minimum x and y coordinates the camera can have.
	public float dampTime = 0.15f;
	private Vector3 velocity = Vector3.zero;

	private Transform player;

	void Awake (){
		player = GameObject.FindGameObjectWithTag("GD").transform;
	}

	void Update (){
		if (player){
			Vector3 point = camera.WorldToViewportPoint(player.position);
			Vector3 delta = player.position - camera.ViewportToWorldPoint(new Vector3(0.5f, 0.2f, point.z)); 
			Vector3 destination = transform.position + delta;
			Vector3 optimalPosition = Vector3.SmoothDamp(transform.position, destination, ref velocity, dampTime);
			optimalPosition = Vector3.Max(minXAndY, Vector3.Min(optimalPosition, maxXAndY));
			optimalPosition.z= transform.position.z;
			transform.position = optimalPosition;
		}
	}
}
