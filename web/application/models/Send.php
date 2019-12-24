<?php
defined('BASEPATH') or exit('No direct script access allowed');

class Send extends CI_model
{
    public function save($fromsensor)
    {
        $this->db->insert('data_sensor', $fromsensor);
        return true;
    }
}
