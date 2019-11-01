<?php
defined('BASEPATH') or exit('No direct script access allowed');

class show extends CI_model
{
    public function showdata()
    {
        $query = $this->db->query("SELECT * FROM data_sensor");
        return $query->result_array();
    }
}
