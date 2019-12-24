<?php
defined('BASEPATH') or exit('No direct script access allowed');

class Show extends CI_model
{
    public function showdata()
    {
        $query = $this->db->query("SELECT * FROM data_sensor ORDER BY waktu DESC");
        return $query->result_array();
    }
}
