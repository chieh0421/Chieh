using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    int score;
    // Use this for initialization
    void Start()
    {
        score = 0;
    }

    // Update is called once per frame
    void Update()
    {

        Vector3 move = Vector3.zero;
        if (Input.GetKey(KeyCode.UpArrow))
        {
            move += 5 * Vector3.forward;
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            move += 5 * Vector3.back;
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            move += 5 * Vector3.left;
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
            move += 5 * Vector3.right;
        }
        GetComponent<Rigidbody>().velocity = move;
    }

    public void addScore()
    {
        score += 1;
        Debug.Log("Score = " + score);
    }
}
